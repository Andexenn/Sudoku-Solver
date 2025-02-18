# Giới Thiệu
Chắc hẳn ai trong chúng ta đều đã từng nghe qua hoặc chơi qua ít nhất một lần `Sudoku`. Đây là trò chơi sắp xếp số rất thú vị và rèn luyện tư duy logic, thậm chí đây còn là một 
bộ môn dùng để thi đấu quốc tế trong các cuộc thi về trí tuệ.

Với `dự án` này, mình cung cấp một công cụ để các bạn kiểm tra đáp án của mình xem liệu đã đúng chưa.

*Lưu ý: mỗi bài `Sudoku chuẩn` chỉ có một và duy nhất một cách giải*.

# Cách Chơi

- Bảng `9x9` được chia thành 9 vùng con, mỗi vùng có kích thước `3x3`
- Một số ô đã được điền sẵn con số, còn lại bàn cần điền vào để hoàn thành
- **Mỗi số trong hàng, cột và ô `3x3` đều phải xuất hiện một lần duy nhất**
- Bạn sẽ phải sử dụng các chiến lược logic để dần điền đầy đủ các ô còn lại sao cho luôn thỏa điều kiện

# Khi Nào Xảy Ra Lỗi?
- **Mâu thuẫn trong các số đã cho**: Thường sẽ không vi phạm luật ngay từ đầu nhưng khi điền các số tiếp theo thì sẽ dẫn đến không còn số nào để điền vào ô trống
- **Không đủ manh mối**: Mỗi bảng Sudoku phải có ít nhất 17 số đã điền thì mới có đủ dữ kiện. Một trường hợp đặc biệt là 0 có số nào đã điền, chắc chắn sẽ luôn có cách giải nhưng chắc chắn lời giải
sẽ không phải là duy nhất.
- **Có nhiều lời giải**: Nếu bạn giải một bài `Sudoku` và phát hiện ra nó có nhiều cách giải thì có lẽ bạn nên bỏ qua nó. Theo quy định của `Sudoku`, mỗi bài chỉ được cho phép tồn tại
duy nhất một cách giải.

# Thuật Toán

Về thuật toán, mình sử dụng backtracking kết hợp với bitmask để có thể tối ưu nhất thời gian giải ra đáp án. Tuy nhiên, có một thuật toán hay hơn, nhanh hơn và mạnh mẽ hơn để giải `Sudoku` là `Dacing Link`.
Tuy nhiên, do giới hạn về khả năng của mình nên là mình chỉ xài backtracking + bitmask. 

Độ phức tạp thuật toán thời gian là O(9^(n*n)) và độ phức tạp không gian là O(n) với n là số ô trống cần phải giải. Điều đó dẫn đến là số ô cho trước phải từ 25 trở lên thì thuật toán của mình mới 
giải nhanh được.

# Kết Luận
Đây là 'dự án' mình lập ra để mọi người có thể check đáp án của những bài `Sudoku` cũng như là có thể xem về thuật toán giải Sudoku.
  

