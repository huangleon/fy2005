// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Ů����");
        set("long", @LONG
���ǹ�����Ů�����ң������ʣ������������г��費�࣬��ȫ��ǡ���ô�����
�е�����һ����ɹ�Ҥ��ƿ�д������µĲ��ż����ող�����Ұ����Ϊ����ƽ����
һ˿���⡣
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"gong",
  "east" : __DIR__"woshi2",
]));
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
