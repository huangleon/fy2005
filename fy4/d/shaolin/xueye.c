// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ҵ��");
        set("long", @LONG
�������ֵ��ӵ���ҵ����ʵ���������䳡�������ǽ�ʵ��Ӳ��������ƽ̹����
��ȴ��͹��ƽ��ʯ����÷��׮����שһӦ��ȫ��ɮ���Ƿ�Ϊ��Ⱥ���򳤹�����󵶣�
���Կ�����
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"jialan",
]));
        set("objects", ([
                __DIR__"npc/monk20" : 1,
                __DIR__"npc/monk20a" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",10);
	set("coor/y",70);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
