inherit ROOM;
void create()
{
    set("short", "������¥");
    set("long", @LONG
��¥�ʷ��Σ��������Ǵ�����Ϣ����Ⱥ�������£���������Ⱥ��΢���еĲʴ�,
�����Ƿ��Ƴǵ����ģ�����������Ҳ������ϡ�Ŀ������ƹ㳡���ĵ�������������
�ķ������಻�ϣ������С·��ϸС�����ߣ����������ڻ�ɫ�ķ���֮��.
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"down" : AREA_FY"wgate",
	"north" : __DIR__"wwall1",
	"south" : __DIR__"wwall10",
      ]));

    set("objects", ([
	__DIR__"npc/a" : 1,
      ]) );



    set("outdoors", "fengyun");
    set("coor/x",-300);
    set("coor/y",0);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
