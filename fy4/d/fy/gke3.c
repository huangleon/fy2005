inherit ROOM;
void create()
{
    set("short", "�ھ��᷿");
    set("long", @LONG
�����ﲼ�úܼ򵥣�ֻ��һ��С����һ��С�����ͼ��ŷ��ʡ���̨�Ϸ���һ��
�ű���������ż�֦����С���������䲻�󣬵��Ǹ����������ʵĸо�������ǽ�
ʨ�ھֵ���ʦ�������ֺͻ����ЪϢ�ĵط���
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"ginhall",
      ]));
    set("objects", ([
	__DIR__"npc/resting_biao" : 2,
	__DIR__"npc/biaotou3" : 1,
      ]) );
    set("coor/x",200);
    set("coor/y",-80);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
