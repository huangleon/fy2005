//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "���");
    set("long", @LONG
�����ɱ���һ���������������죬��û��ͤ��֮�С���ֵ�����������ͨ
���ĳ����������빤ֱ�������о�������һ������ׯ�µ�������������ס����
����Ц�⡣·������ͷ������������ת����ĸ���֮����
LONG
    );
    set("exits",
      ([
	"west" : __DIR__"3xian",
	"north": __DIR__"yiye",
	"enter" : __DIR__"wangxian", 
	"south": __DIR__"treasure",
      ]));
    set("objects",
      ([
	//	     __DIR__"obj/sand" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",20);
    set("coor/y",-160);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
