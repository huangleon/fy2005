inherit ROOM;
void create()
{
        set("short", "��˹����");
        set("long", @LONG
��˹������ά������˼�ǡ��׸�����Ĺ�ᰴ���������ÿһ������й̶�
��Ĺ�أ�����ʯΪ�磬ÿ��Ĺ���������б��Ĺ������Ĺ�ҡ�Ĺ����Ĺ�Ҷ�������
һ�㶼�Ѱ���ʯ��ƽ��ʡ��ס����Ρ�
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"emin",
]));
        set("objects", ([
        __DIR__"npc/ghost" : 3,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",80);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
