inherit ROOM;
void create()
{
        set("short", "�Ϸ���");
        set("long", @LONG
����Ľֵ������ɾ�������������·�汻��ˮ��ù����羵���ֵ������
�߷��ߴ����ΰ�������Ǿ޸�լԺ��˫�˺ϱ�������ʮ��һ�꣬������������ߡ�
�������һ��ǧ��޶����������������ԡ�������ǽ�Ǯ����ܶ档
��ֶ����լ����һ�߸ߵ�ʮ�ּܣ�һЩ�𷢱��ۣ��������۵��˲�ʱ�ĳ������롣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind3",
  "north" : __DIR__"swind1",
  "east" : __DIR__"church",
  "west" : __DIR__"jinqian",
]));
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",-20);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
