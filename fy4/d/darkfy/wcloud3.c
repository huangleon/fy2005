inherit ROOM;
void create()
{
        set("short", "���ƴ�·");
        set("long", @LONG
���Ļ���·����������չ��·�ߵ�é�ݰ�С���ƾɣ��ֱߵ�����ɢ����
������Ż�ĸ�����·�ϵ�������Ƽ��ݣ���ƶ���������ϵ�ƣ��������ż����һ
������ɫ����֮�ˣ����ڱǴҴҶ���������մ��һ�������������һ��ľ�ţ���
��д����ÿҹ��ʮ�ģ��������������ʦ�ѳɹ�����ƣ������Ѳ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"futhur",
  "south" : __DIR__"cheaph",
  "west"  : __DIR__"wcloud4",
  "east"  : __DIR__"wcloud2",
]));

        set("outdoors", "fengyun");
        set("coor/x",-30);
        set("coor/y",0);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
