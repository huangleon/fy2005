// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ӭ����");
        set("long", @LONG
һ������������ԶԶ��ɿ���һ����������˫�ۡ�������������ӭ��Զ����
���Ŀ��ˡ��ɸ�ʮ���ף�����ï�ܣ�����ӭ���ɣ���־�������Ѿ�̤�롰��ɽ��
���£������Դ��С�������Ժ�ˡ�
LONG
        );
        set("exits", ([ 
  "eastdown"  : __DIR__"guanyin",
  "southwest" : __DIR__"yuping",
  "northwest" : __DIR__"wenzhu",
]));
        set("objects", ([
        __DIR__"npc/huo" : 1,
	__DIR__"npc/du" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-60);
	set("coor/y",10);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
