inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
���¾���ר�Ÿ����Ǯ���ܶ�İ�ȫ���������˶�Ҫ�������ǵ���ϸ�̲顣��
���������ְ���Ϣ�����ڡ������м���С��������С����ÿ�Ŵ�ͷ����С��������
�Ƕ��ѱ������ڹ��ϣ�һ���־Ϳ����������ٶȰγ��Լ��ı��С�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
			"south" : __DIR__"jting",
			"east" : __DIR__"tang1",
			"west" : __DIR__"tang2",
			"north" : __DIR__"tang3",
      ]));
    set("objects", ([
	__DIR__"npc/huangyi" : 2,
	__DIR__"npc/huangyi2" : 1,
      ]) );
	set("NONPC",1);			// to stop dungeon NPCs to come out.
    set("coor/x",-180);
    set("coor/y",100);
    set("coor/z",0);

    set("map","fywest");
    setup();
    replace_program(ROOM);
}
