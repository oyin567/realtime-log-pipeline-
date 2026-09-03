const express = require('express');
const app = express();

app.get('/cause-error', (req, res, next) => {
  const err = new Error('Database connection dropped');
  err.status = 500;
  next(err);
});

// Global Error Handler Middleware
app.use((err, req, res, next) => {
  const statusCode = err.status || 500;
  res.status(statusCode).json({
    error: {
      message: err.message || 'Internal Server Error',
      status: statusCode,
      timestamp: new Date().toISOString()
    }
  });
});

app.listen(3000, () => console.log('Error Handler active on port 3000'));
