#include <ansi.h>
inherit ROOM;

int event_msg();

void create()
{
        set("short", "����С��");
        set("long", @LONG
С�����û�еƹ⣬һ�㶼û�С�һ��˵��������ɭ������������ͬ���
ʯ���·����ʯ����Ұ�ݾ�������ߣ���Ȼ��ط�ƽʱ���������������������ǰ�
��ɫ�ĸ�ǽ��û�д��ӣ�Ҳû��������
LONG
        );
        set("exits", ([ 
		"west": __DIR__"droad0",
		"east": __DIR__"droad2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		"grass":	"С�����ˣ�Ұ���Ѿ���������ˡ�\n",
		"Ұ��":		"С�����ˣ�Ұ���Ѿ���������ˡ�\n",    
		"corner":	"ǽ������ˮ��С�������ֻ�������������\n",
		"��":		"ǽ������ˮ��С�������ֻ�������������\n",
	]));
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

void init(){
	if (random(2)) {
		remove_call_out("event_msg");
		call_out("event_msg",random(5)+1);
	}
}

int event_msg() {
	message("vision",BLU"��֪ʲô����������´ܹ������ǽ�ǵĶ��ﲻ���ˡ�\n\n"NOR,this_object());
	return 1;
}