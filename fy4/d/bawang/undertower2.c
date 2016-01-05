#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ǽ��");

	set("long", @LONG
ԭ����ҡҡ��׹�Ķ�����������ֵľ綷֮��ֻʣ��һƬ��ǽ��ԫ������һƬ
�ž�����紵����ֻ�����µ��ǿ��������ڷ��л������죬��Ӱ��涣��������ߡ�	
LONG);

	set("type","street");
	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",-10);
	set("exits",([
		"east":__DIR__"undertower",
	]));
		
	set("objects",([
		__DIR__"obj/brokenwall":1
	]) );
	set("outdoors", "bawang");
	setup();
}

void init ()
{
	add_action("do_push", "push");
}

int do_push(string arg)
{
	if(!arg || arg=="")
	{
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	if( arg == "duanqiang" || arg == "��ǽ" || arg == "��ǽ" 
		|| arg == "wall" || arg == "��ǽ��ԫ")
	{
		object me, room;
		me = this_player();
		if(me->query("kar")+random(50) < 25){
			message_vision(HIY"$N������˫�ۣ����ؽ�ҧ��˫ĿԲ�������һ������������\n\n"NOR, me);
			if(me->query("gender") == "male"){
				message_vision(HIY"ֻ�����ԣ�����һ����\n\n"NOR, me);
				message_vision(HIY"$N�Ŀ�����������......\n"NOR, me);
			} else {
				message_vision(HIY"$N������ͨ�죬��ǽ������˿������\n"NOR, me);
			} 	
		return 1;
		}
		if(me->query("str") < 14){
			tell_object(me,HIR"������Σǽ�����������޸���֮����ʹ�˳��̵���������ǽ������˿������\n");
			return 1;
		} else if(me->query("str") + random(20) < 24) {
			tell_object(me,HIR "������һ�ƣ���ǽ�ƺ���Щ�ζ�����ž���������ͷ��һ���ʹ��
ԭ����һ��שͷ��ǽͷ���������������������ͷ����!�����һ��������ת��\n"NOR);
			me->set_temp("last_damage_from","��שͷ�����ˡ�\n");
			me->receive_damage("kee",random(100)+30);
			me->receive_damage("gin",random(100)+30);
			return 1;
		 }else{
			message_vision(HIW"\n$N������˫�ۣ����ؽ�ҧ��˫ĿԲ�������һ������������\n\n", me);
			message_vision(HIW"ֻ������¡��һ������ǽһ���ӵ���������\n\n"NOR, me);
			tell_object(me, "�ڲ�ש����֮�����ƺ��ҵ���һ�����ص���ڡ�\n");
			if( !query("exits/enter") ) {
				set("exits/enter", __DIR__"andao1.c");
				call_out("close_path", 3);	
			}
			return 1;
		}
	}
}

void close_path()
{
	if( !query("exits/enter") ) return;
	message("vision", "��ש��ʯ�׷����¡�������\n",this_object());
	delete("exits/enter");
}
