inherit ROOM;
void create()
{
    set("short", "����С��");
    set("long", @LONG
����������Ҳ�����ӵİ׾ơ�һ���Ѿ����糶�ѵľ����ϻ���һ���ú�Ȧ����
�ġ��ơ��֡�������ͳ���һ��ҵ�ѱ�ڵİ׷������ײ��·��ż����ƾɵ�ľ����
���ʣ�ľ��������ɢɢ�ط��ż�˫ľ��ͼ������˿ڵ�С������
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"lssquare1",
      ]));
    set("objects", ([
			__DIR__"npc/wineowner" : 1,
			"/obj/npc/inform_beggar":1,
      ]) );

    set("coor/x",120);
    set("coor/y",100);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
