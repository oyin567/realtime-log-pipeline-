<!DOCTYPE html>
<html>
<head>
  <style>
    body { font-family: sans-serif; padding: 20px; }
    input { padding: 8px; width: 100%; max-width: 300px; margin-bottom: 15px; }
    .log-item { padding: 8px; border-bottom: 1px solid #ccc; }
  </style>
</head>
<body>
  <input type="text" id="searchInput" placeholder="Search endpoint or status...">
  <div id="logContainer"></div>

  <script>
    const logs = [
      { id: 1, text: "GET /api/v1/users - 200 OK" },
      { id: 2, text: "POST /api/v1/auth - 401 Unauthorized" },
      { id: 3, text: "GET /health - 200 OK" }
    ];

    const searchInput = document.getElementById('searchInput');
    const container = document.getElementById('logContainer');

    function render(items) {
      container.innerHTML = items.map(item => `<div class="log-item">${item.text}</div>`).join('');
    }

    searchInput.addEventListener('input', (e) => {
      const query = e.target.value.toLowerCase();
      const filtered = logs.filter(l => l.text.toLowerCase().includes(query));
      render(filtered);
    });

    render(logs);
  </script>
</body>
</html>
