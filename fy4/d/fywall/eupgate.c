inherit ROOM;
void create()
{
    set("short", "������¥");
    set("long", @LONG
��¥�ʷ��Σ��������Ǵ�����Ϣ����Ⱥ�������£���������Ⱥ��΢���еĲʴ���
�����Ƿ��Ƴǵ����ģ�����������Ҳ������ϡ�Ŀ������ƹ㳡���ĵ�������������
�ķ������಻�ϣ������С·��ϸС�����ߣ����������ڻ�ɫ�ķ���֮�䡣
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"down" : AREA_FY"egate",
	"north" : __DIR__"ewall1",
	"south" : __DIR__"ewall10",
      ]));

    set("objects", ([
	__DIR__"npc/d" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",300);
    set("coor/y",0);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
