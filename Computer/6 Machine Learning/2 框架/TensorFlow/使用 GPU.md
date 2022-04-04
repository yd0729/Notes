无需更改任何代码，TensorFlow 代码以及 `tf.keras` 模型就可以在单个 GPU 上透明运行。

注：使用 `tf.config.experimental.list_physical_devices('GPU')` 可以确认 TensorFlow 使用的是 GPU。

TensorFlow 支持在各种类型的设备上执行计算，包括 CPU 和 GPU。我们使用字符串标识符来表示这些设备，例如：

- `"/device:CPU:0"`：机器的 CPU。
- `"/GPU:0"`：TensorFlow 可见的机器上第一个 GPU 的速记表示法。
- `"/job:localhost/replica:0/task:0/device:GPU:1"`：TensorFlow 可见的机器上第二个 GPU 的完全限定名称。

如果一个 TensorFlow 运算同时有 CPU 和 GPU 实现，默认情况下，将运算分配给设备时优先使用 GPU 设备。例如，`tf.matmul` 同时有 CPU 和 GPU 内核。在具有 `CPU:0` 和 `GPU:0` 设备的系统上，将选择 `GPU:0` 设备来运行 `tf.matmul`，除非明确要求在另一个设备上运行。

为了找出将运算和张量分配到的目标设备，请将 `tf.debugging.set_log_device_placement(True)` 放在程序的第一行。启用设备放置记录将导致任何张量分配或运算被打印。

如果您希望在自己选择的设备上执行特定运算，而不是在自动选择的设备上执行，则可以使用 `with tf.device` 创建设备上下文。创建完成后，该上下文中的所有运算都会在同一指定设备上运行。

```python
tf.debugging.set_log_device_placement(True)

# Place tensors on the CPU
with tf.device('/CPU:0'):
  a = tf.constant([[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]])
  b = tf.constant([[1.0, 2.0], [3.0, 4.0], [5.0, 6.0]])

c = tf.matmul(a, b)
print(c)
```

