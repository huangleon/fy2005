
inherit ROOM;

void create()
{
        set("short", "�̷�");
        set("long", @LONG
�����̷��ѱ�Ǭ�µ�Ѫ��Ȼ�ɰ���ɫ��ɢ�����˱ǵ��ȳ���ǽ�Ϲ����˸�ʽ��
�����Ͼߡ��̷��ĵ���ɢ�����������������������á�ż��֮�䣬�㻹��������
����֨֨���ļ������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  			"west" : __DIR__"tunnel5",
  			"north" : __DIR__"tortureroom2",
		]));
        set("objects", ([
                __DIR__"npc/highrat": 2, 
		__DIR__"npc/guard2" : 2,

		]) );

	set("coor/x",20);
	set("coor/y",30);
	set("coor/z",5);
	setup();
}

