## Smart Pointer

Smart pointer là các class template được tạo ra để quản lý tài nguyên tốt hơn.

Pointer thường được sử dụng để truy cập tài nguyên từ vùng nhớ Heap. Tài nguyên hay dữ liệu tại vùng nhớ heap được cấp phát và giải phóng trong quá trình run-time.

Điểm hạn chế của rawpointer là việc cấp phát và giải phóng do lập trình viên phải thực hiện (new, delete). Chẳng hạn nếu cấp phát tài nguyên trên vùng nhớ heap mà quên không giải phóng sẽ dẫn đến bộ nhớ heap bị đầy và gây ra crash chương trình.

```
class Temp;

while(1)
{
	Temp t = new Temp();
	// Need to delete t
}
```

Smart pointer sẽ tự động cấp phát và giải phóng khi ra khỏi phạm vi của nó.
C++ có các smart pointer như sau:

- std::unique_ptr
- std::shared_ptr
- std::weak_ptr
- std::auto_ptr

### std::uinque_ptr

Loại này khi ra khỏi phạm vi code của nó, nó sẽ tự động giải phóng tài nguyên, và là unique nên class này không có phép gán, do vậy không thể gán con trỏ này cho bất kỳ một con trỏ nào khác.

### std::shared_ptr

Loại này sử dụng một biến đếm (reference counter) để quản lý các con trỏ đang được trỏ vào tài nguyên. Khi con trỏ cuối cùng bị xóa (reference counter = 0) thì tài nguyên sẽ được giải phóng.

### std::weak_ptr

### std::auto_ptr