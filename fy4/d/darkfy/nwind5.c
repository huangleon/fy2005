inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������･����խ���ֵ����Եĵ���Ⱥ�����ֲβ�롣�ֵĶ�����һ��С
С�ĳ����������ƾɲ�����������ϡ����ľ̿Ϳ��һ֧�֣���ֻ�����ƺ�ץ��ʮ
��֧�̼�����˵�������ϳ��й��ĳ��֡��ֵ���������һ�Ұ��ӵꡣ
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nwind4",
  "north" : __DIR__"ngate",
  "east" : __DIR__"hiretem",
  "west" : __DIR__"baozipu",
]));
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",50);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
