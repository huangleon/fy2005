inherit ROOM;
void create()
{
    set("short", "���᷿");
    set("long", @LONG
�����ﲼ�úܼ򵥣�ֻ��һ��С����һ��С�����ͼ��ŷ��ʡ���̨�Ϸ���һ��
�ű���������ż�֦����С���������䲻�󣬵��Ǹ����������ʵĸо�������ǽ�
ʨ�ھֵ���ʦ�������ֺͻ����ЪϢ�ĵط����ӱ��ų�ȥ�����ھֵĺ�Ժ�ˡ�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"ginhall",
	"east" : __DIR__"backdoor",
      ]));
    set("objects", ([
	__DIR__"npc/resting_biao" : 2,
	__DIR__"npc/biaotou1" : 1,
      ]) );

    set("coor/x",220);
    set("coor/y",-60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
