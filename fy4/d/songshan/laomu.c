// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ĸ��");
        set("long", @LONG
�ӳ縣�����⣬ɽ·���ѣ���������ɽ�Ҽе����������߶��У����˳���ĸ����
�ഫ��һ�Ŵ�����Ϊ�ȱ����޶��ߵ�ĸ�ף�����ɽʯ��·���б�����������ôһ��
�վ����ڣ�����������У����Ǿ������ˡ�
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"junji", 
  "south" : __DIR__"chongfu",
]));
        set("outdoors", "songshan");
        set("objects", ([
                __DIR__"npc/zihe" : 1,
       ]) );
	set("coor/x",15);
	set("coor/y",30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
