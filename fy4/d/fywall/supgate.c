inherit ROOM;
void create()
{
    set("short", "�ϳ���¥");
    set("long", @LONG
��¥�ʷ��Σ��������Ǵ�����Ϣ����Ⱥ�������£���������Ⱥ��΢���еĲʴ�,
�����Ƿ��Ƴǵ����ģ�����������Ҳ������ϡ�Ŀ������ƹ㳡���ĵ�������������
�ķ������಻�ϣ������С·��ϸС�����ߣ����������ڻ�ɫ�ķ���֮��.
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"down" : AREA_FY"sgate",
	"east" : __DIR__"swall1",
	"west" : __DIR__"swall10",
      ]));
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-300);
    set("coor/z",30);
    set("objects", ([
	__DIR__"npc/g" : 1,
      ]) );


    setup();
    replace_program(ROOM);
}
