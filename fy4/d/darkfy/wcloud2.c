inherit ROOM;
void create()
{
        set("short", "���ƴ�·");
        set("long", @LONG
Ҳ���ǿ쵽���ƹ㳡��ԭ�ʣ���������ս������������������Ѳ��ǿ�����ƽ
�Ļ���·�����ĺ�ʯ���ɵĴ�·���ݰ����У�·�ϵ����˽Ų���죬���鿪�ʣ�
��·���ϲ��Ƿ��Ƴ��е�֪�����ţ���·�ı����Ƿ�����վ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"mailst",
  "south" : __DIR__"govern",
  "west"  : __DIR__"wcloud3",
  "east"  : __DIR__"wcloud1",
]));

        set("outdoors", "fengyun");
        set("coor/x",-20);
        set("coor/y",0);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
