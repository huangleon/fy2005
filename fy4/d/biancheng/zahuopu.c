inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ӻ���");
        set("long", @LONG
�ӻ��̵��ϰ壬�Ǹ����ֹ۵������ˣ�ԲԲ���������ۿ���˭����Ц���еġ�
����Ҫ���⼸��Ǯ����ץ���Ѷ��ӣ���Ҳ����Ц������˵�����ðɣ����������ˣ�
�������ǽַ��ھ������������˶�������������ʱ���ӻ����������˻���
��ˣ������ֺ�ƽʱһ�������ڹ�̨�ϴ��˯��
LONG
        );
        set("exits", ([ 
	"east" : __DIR__"sstreet3",
	]));
        set("objects", ([
        	__DIR__"npc/limahu":	1,
	]) );
	set("coor/x",-20);
        set("coor/y",-30);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
