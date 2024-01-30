<?php
$ffi = FFI::cdef("
    void dijkstra(int n, int graph[5][5], int source, int* dist);
", "path/to/libdijkstra.so");

$graph = [
    [0, 6, 0, 1, 0],
    [6, 0, 5, 2, 2],
    [0, 5, 0, 0, 5],
    [1, 2, 0, 0, 1],
    [0, 2, 5, 1, 0]
];

$source = 0;
$dist = FFI::new("int[5]");

$ffi->dijkstra(5, $graph, $source, $dist);

echo "Shortest distances from node $source:\n";
for ($i = 0; $i < 5; $i++) {
    echo "To node $i: " . $dist[$i] . "\n";
}
?>
