const express = require('express');
const http = require('http');

const app = express();
app.use(express.json());

const logs = [
  { id: 1, ip: '127.0.0.1', status: 200, endpoint: '/api/v1/metrics' },
  { id: 2, ip: '10.0.0.2', status: 403, endpoint: '/admin' }
];

app.get('/api/logs', (req, res) => {
  res.json({ success: true, count: logs.length, data: logs });
});

app.post('/api/logs', (req, res) => {
  const { ip, status, endpoint } = req.body;
  const newLog = { id: logs.length + 1, ip, status, endpoint };
  logs.push(newLog);
  res.status(201).json({ success: true, data: newLog });
});

const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Log Engine API running on http://localhost:${PORT}`);
});
