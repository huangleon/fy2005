// searoad.c
inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
·���ϵ�ɳʯԽ��Խϸ��������������һ����ζ��Խ��ǰ�ߣ���ζԽ���ԡ�Զ
���������������İ���������ż���߹�ȥһ��������ˮ�Ƶ�����򣬼��Ͽ�����ߣ�
ˬ�ʵش���̸Ц��
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"searoad",
  		  "south" : __DIR__"seaside",
  		  "north":  __DIR__"seaside1",
		]));         
	set("objects",([
        	AREA_TIEFLAG"npc/fishman" : 1,
       	]) );
        set("outdoors", "tieflag");
	set("coor/x",1000);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
