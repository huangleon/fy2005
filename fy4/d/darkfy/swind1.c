inherit ROOM;
void create()
{
        set("short", "�Ϸ���");
        set("long", @LONG
�������ߣ����Ƿ��Ƴǵ����Ĺ㳡������պ���ס�ڳ��ϵĴ��˼�ȥ���е�
�ؾ�֮·�����������˵����������εķ��١��������������鱦���˽��˳���ӵ
����������������ר��Ϊ��Ǯ�˵�Զ�����ѵ����Ƴ�����ʱ��׼���ķ���˿�ջ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind2",
  "north" : __DIR__"fysquare",
  "east" : __DIR__"fqkhotel",
  "west" : __DIR__"yuljade",
]));
        set("outdoors", "fengyun");


        set("coor/x",0);
        set("coor/y",-10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
