// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�縣��");
        set("long", @LONG
��ɽ����������֮�أ��縣���Ǵ����ۣ��������Ĺ������̵��徲��Ϊ����
���ͬ���������ȣ���ɫǽ����͸�Ų�ͬ�ķ�񡣴����ﱱ�б�����ĸ��������
�����������£����Եó縣��֮���ڲ�ͬ��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"laomu", 
  "west" : __DIR__"shuyuan",
]));
        set("objects", ([
                __DIR__"npc/daoshi" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",15);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
