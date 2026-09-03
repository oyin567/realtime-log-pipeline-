const express = require('express');
const fs = require('fs');
const path = require('path');
const app = express();

app.get('/api/logs/stream', (req, res) => {
  const logFilePath = path.join(__dirname, 'access.log');
  
  if (!fs.existsSync(logFilePath)) {
    return res.status(404).json({ error: 'Log file not found' });
  }

  res.setHeader('Content-Type', 'text/plain');
  const readStream = fs.createReadStream(logFilePath, 'utf8');
  
  readStream.pipe(res);
  readStream.on('error', (err) => {
    res.status(500).end('Streaming error');
  });
});

app.listen(3000);
