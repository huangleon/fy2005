inherit ROOM;
void create()
{
    set("short", "�����");
    set("long", @LONG
�������ü򵥣�����̫ʦ��Χ��һ�Ű������������������һЩС������ĳ�
��Ʒ��ÿ���紵���ţ��ſڵķ��巢��ɳ�Ƶĵ�������ש�̵أ������ƺ���������
����ɫ�Ļ��ơ��������Ҹ���С�š�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"jinqian",
	"north" : __DIR__"jhuang",
	"south" : __DIR__"jhuang1",
      ]));
    set("coor/x",-180);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}
