inherit ROOM;
void create()
{
    set("short", "������¥");
    set("long", @LONG
¥�ʷ��Σ��������Ǵ�����Ϣ����Ⱥ�������£���������Ⱥ��΢���еĲʴ�,
�Ϸ��Ƿ��Ƴǵ����ģ�����������Ҳ������ϡ�Ŀ������ƹ㳡���ĵ�������������
�ķ������಻�ϣ������С·��ϸС�����ߣ����������ڻ�ɫ�ķ���֮��.
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"down" : AREA_FY"ngate",
	"west" : __DIR__"nwall1",
	"east" : __DIR__"nwall10",
      ]));
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",300);
    set("coor/z",30);
    set("coor/x",0);

    set("objects", ([
	__DIR__"npc/j" : 1,
      ]) );

    set("coor/y",180);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
