inherit ROOM;
void create()
{
        set("short", "ǰ��԰");
        set("long", @LONG
ǧ��¥����֮����������Լ�һ�ߣ��ı߻������࣬��Ψ��ĵ����ʤ���ǻ���
��Ѱ����¥��֮�࣬�ˡ�Ҧ�ơ���κ�ϡ�������Ʒ��һ����ֵ��ǧ���ǻ���������
�Ŷ��棬��Χ�Ժ�ʯ��֮���仨���絤�̣���ɫ���ã��⻪��Ŀ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"garden",
]));
        set("objects", ([
        __DIR__"npc/huajiang": 1,
                        ]) );

	set("outdoors","fengyun");
	set("coor/x",-5);
	set("coor/y",5);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
