inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "������ͷ");
        set("long", @LONG
�������û�о��µİ��裬Ҳû�л�����װ�Σ���ȴ�Ե�˵������ׯ�ϡ����¡�
�߹󡢲�������˭�ߵ�������鶼�᲻�������ľ���������������������ľ�
ͷ����һ�ſ��Ľ����ϣ�����һ�������ˡ���������ô��һ���ˣ�˭Ҳ����̫��
����ֻ�������˶��������������
LONG
        );
        set("exits", ([ 
	"south": __DIR__"hall3",
	"west": __DIR__"pianting2",
	]));
        set("objects", ([
        	__DIR__"npc/makongqun":	1,
	]) );
        set("coor/x",-10);
        set("coor/y",130);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
