// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "���ַ�");
        set("long", @LONG
����ɽ��ʵ���Ƕ࣬�ഫ��ɽ��ǧ���ٷ壬�ӵ��ַ�������ֻ�����й�֮����
��һ��ɽ������Լ��㣬Ⱥ����֣�����һ������������Ⱥ�壬Ҳ��˵�徿������
���٣�������ʯ�ף����������˱���ԱȽ����ɵĵ����ɽ���ɹ��֡�
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"qingliang",
  "west" : __DIR__"sroad",
]));
        set("objects", ([
        __DIR__"npc/dizi" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-130);
	set("coor/y",-30);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
