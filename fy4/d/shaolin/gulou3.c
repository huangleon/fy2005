// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
�������ϱ��Ǵ��¥���޹ı������档ǽ�ϵıڻ��ƺ����汥��������ķ���
��ϸһ����ȴʵ����̫ģ���ˣ�ʲôҲ�����ˡ�
LONG
        );
        set("exits", ([ 
  		"up" : __DIR__"gulou4",
  		"down" : __DIR__"gulou2",
	]));
        set("objects", ([
                BOOKS"skill/buddhism_30" : 1,
                __DIR__"npc/monk52" : 1,		
       ]) );
	set("coor/x",-10);
	set("coor/y",-60);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
