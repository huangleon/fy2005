inherit ROOM;
void create()
{
        set("short", "�Ϸ���");
        set("long", @LONG
����Ľֵ������ɾ�������������·�汻��ˮ��ù����羵���ֵ������
�߷��ߴ����ΰ�������Ǿ޸�լԺ��˫�˺ϱ�������ʮ��һ�꣬������������ߡ�
ֻ�������ϵ�С��ʱ����ʱ��������������ﵽ����ɢ���Ű������������ա�
�ֵ������������ã����������Ϲ�Ǯׯ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"sgate",
  "north" : __DIR__"swind4",
  "east" : __DIR__"nanbank",
  "west" : __DIR__"pusheng",
]));
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",-50);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
