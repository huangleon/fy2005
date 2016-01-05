#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�Խ�ʯ");
	set("long", @LONG
һ��޴��ʯͷ���´�·�У��м�һ�ۣ�����룬�ഫ����һ�Ŵ���ʦ�Խ�
֮��������ǧ�࣬����������һ�ѿ���������ʯ�Ľ�����Ϊ������񽣡�����ϧ��
ʦ�������㲶������ഫ��ɽ��®���������ഫ�ı��Ǵ˽���
LONG
	);
	set("exits", ([ 
	"north"  : __DIR__"zuishi",
	]));
	set("item_desc", ([
"stone": "һ��޴��ʯͷ���м�һ�ۣ��ѷ���ƺ���һ
�����������⡣���ƺ�Ҳ������������һ�ԣ������������������\n",
		"ʯͷ": "һ��޴��ʯͷ���м�һ�ۣ��ѷ���ƺ���һ
�����������⡣���ƺ�Ҳ������������һ�ԣ������������������\n",
		"rock": "һ��޴��ʯͷ���м�һ�ۣ��ѷ���ƺ���һ
�����������⡣���ƺ�Ҳ������������һ�ԣ������������������\n",

	]) );
    
	set("outdoors", "huangshan");
	set("coor/x",-40);
	set("coor/y",-20);
	set("coor/z",10);
	setup();
}

void init()
{
	add_action("do_test","test");
}

int do_test(string arg)
{
	object me,weapon;
	if(!arg ) return notify_fail("��Ҫ��һ�������ϵ�����������\n");
	me=this_player();
	
	if(!(weapon = present(arg,me))) return notify_fail("�������ƺ�û������������\n");
	if(!weapon->query("weapon_prop")) return notify_fail(weapon->name()+"�ƺ�������һ��������\n");
	if(!weapon->query("equipped")) return notify_fail("�㲢û�н�"+weapon->name()+"�������С�\n");

	message_vision(WHT"$N�þ�ȫ���������е�"+weapon->name()+"�������ʯ��ȥ��������\n"NOR,me);
	
	if (me->query("max_force")< 1000)
		return notify_fail("�������̫С������ʯ�����ҡҡ�λΣ���Ҫ1000�����������\n");
	
	weapon->unequip();
	if(weapon->query("owner")){
		weapon->set("orig_name", weapon->query("name"));
		weapon->set("weapon_prop/damage",1);
        weapon->set("item_damaged", 1);
	} else {
		weapon->set("weapon_prop",0);
	}
	
	message_vision(HIG"ֻ������������һ����$N���е�"+weapon->name()+"Ӧ�����ϣ�
$N�������Ѫ��ӿ�������ڵ�����ʮ����һ�ӵ����ڵأ����ζ�û��������\n"NOR,me);
		
	weapon->set("name","�ϵ���" + weapon->query("name"));
	weapon->set("item_damaged", 1);
	weapon->set("value",0);
	weapon->save();
	me->reset_action();
	
		message_vision(BLU"һ�������Ķ�����ʯ���е��˳�������$N���У�\n"NOR, me);
		weapon = new(__DIR__"obj/banzhi");
		weapon->move(me);
		weapon->set("no_drop",1);
	
	me->perform_busy(10);
	return 1;
}
