
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����������ʪ���ƾɲ���������ΰ�����Ĳ��������г������ĶԱȡ�ÿһ����
���������˶��е�����˥�ϣ�ĺ�����������о����ƺ���ľ��������
LONG
        );

        set("valid_startroom", 1);
        set("exits", ([ 
  		"east" : __DIR__"tower",
	]));
        set("objects", ([
                __DIR__"npc/lama3" : 3,
		__DIR__"npc/master" : 1,
//        __DIR__"npc/yellama" : 1,
		__DIR__"obj/ironstaff" : 1,
        ]) );
	set("coor/x",-5);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

