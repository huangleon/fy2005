//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "���");
    set("long", @LONG
�����ɱ���һ���������������죬��û��ͤ��֮�С���ֵ�����������ͨ
���ĳ����������빤ֱ�������о�������һ������ׯ�µ�������������ס����
����Ц�⡣
LONG
    );
    set("exits",
      ([
	"east" : __DIR__"3xian",
	"south": __DIR__"caiyun", 
	"north": __DIR__"fuyun",
	"west":  __DIR__"lanke",
      ]));
    set("objects",
      ([
	//	     __DIR__"obj/sand" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",-10);
    set("coor/y",-160);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
