inherit ROOM;
void create()
{
        set("short", "���ƴ�·");
        set("long", @LONG
���ƹ㳡�ڶ���֪�����������������Ƿ��Ƴ��з�ɧ���˴Ծ�֮�ء���˵����
�պ�������С��̽�������������е���š��ϱߵĿ���ÿ�궼����һ��ѡ�ο��ԣ�
ǰ�������뾩�����ԡ���������̽��ʫ̨���Ƿ�ɧ�������������ǵ���֮���ĵ�
����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"poemp",
  "south" : __DIR__"examp",
  "west"  : __DIR__"wcloud2",
  "east"  : __DIR__"fysquare",
]));
        set("objects", ([
        __DIR__"npc/xiwei": 1,
                        ]) );


        set("outdoors", "fengyun");
        set("coor/x",-10);
        set("coor/y",0);
        set("coor/z",-300);
        setup();
}
