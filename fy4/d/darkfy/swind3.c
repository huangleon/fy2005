inherit ROOM;
void create()
{
        set("short", "�Ϸ���");
        set("long", @LONG
����Ľֵ������ɾ�������������·�汻��ˮ��ù����羵���ֵ������
�߷��ߴ����ΰ�������Ǿ޸�լԺ��˫�˺ϱ�������ʮ��һ�꣬������������ߡ�
һ���������������ڴ������һ����լ�ķ����£������ŷ��Ƴ�������ĵ�����
�ķ��������ķ��Ķ�������һƷ�Ӳ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind4",
  "north" : __DIR__"swind2",
  "east" : __DIR__"yitea",
//  "west" : "/d/yingou/yingou", Shall me make another 
]));
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",-30);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
