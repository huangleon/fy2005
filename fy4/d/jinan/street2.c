// street2.c

#include <room.h>
inherit ROOM;
void create()
{
  set("short","�۴�ͤ");
  set("long",@LONG
���ϴ������������ûʵ�ͤ�ӣ���˵�ǵ���ؤ���ϰ����δȳ������ݶ��ɣ�
�Ա�����·���ڷ絲�ꡣ���ڴ�ͤ������Զ�����������Ľ��ӣ������ſ�ͻ�����룬
����ͤΪ���۴�ͤ����ȡ���Է��ӵġ�������˹�򡻡����漸��������ŵı�����
[33mؤ��[32m�ڼ��ϳ��޽������á����ƹ�������������ͨ������֮��[33m��̩ɽ��[32m��ɽ����
LONG
  );
  set("exits",([
         "north":__DIR__"street1",
         "southup":__DIR__"street3",
         "west":__DIR__"shungeng",
         "east":__DIR__"lake"
               ]));
    set("outdoors", "jinan");
	set("coor/x",0);
	set("coor/y",80);
	set("coor/z",0);
	setup();
    replace_program(ROOM);

}

