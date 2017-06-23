#创建sequence序列
create sequence sw_sequence START WITH 1 INCREMENT BY 1 NOMAXVALUE NOCYCLE CACHE 20;

#创建表matched_record
create table matched_record(log_id number Primary key, log_name VARCHAR2(32), pid number, login_time number, logout_time number, duration number, log_ip VARCHAR2(32));

#创建触发器sw_tr 用来对matched_record中的主键赋值
create or replace trigger sw_tr
before insert on matched_record
for each row 
begin 
select sw_sequence.nextval into :new.log_id from dual;
end;
/

