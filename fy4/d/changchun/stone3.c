inherit DOOR_ROOM;
#include <room.h>
void create()
{
	set("short", "�ص�");
	set("long", @LONG
�����Ǹ�Բ��ʯ��������������׺֮���ʣ����֮ëƤ������һ��һ�Σ�����
��ʯ��̶��ɣ���ɫ��ͬ�����߽��ġ��Ƕ�Ʈ��һ�󵭵��������������������
�����£�ʯ���ԣ��ͼ�ǰ����վ��ʮ�����������Ů�������е�������ɴ���е�
���Ž��ۣ��е�����̸Ц���е��������壬Ҳ�е�������ױ�����е�������ͼ��
LONG
	);
	set("exits",([
	
		"east" : __DIR__"stone2",
	
	]) ); 
	set("objects",([
		AREA_TIEFLAG"obj/tieflag2" : 2,
		AREA_TIEFLAG"npc/o_girl" : 1,
		AREA_TIEFLAG"npc/b_girl" : 1,
		AREA_TIEFLAG"npc/r_girl" : 1,
	]) );	
	set("coor/x",80);
	set("coor/y",-20);
	set("coor/z",-30);
	setup();
	create_door("east","door","����ʯ��","west",DOOR_CLOSED);
}
