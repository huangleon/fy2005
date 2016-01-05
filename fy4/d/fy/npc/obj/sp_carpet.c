// magic carpet,annie 7.03.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("��̺" NOR, ({ "carpet" }) );
    set_weight(800);
			if( clonep() )
            set_default_object(__FILE__);
    else {

            set("unit", "��");
            set("material", "cloth");
            set("long", "һ������������̺����˵�ܴ���������ء�\n");
			set("value",1000);
			set("closed", 1);
			set("desc_ext","����(fly)");
		  }
    ::init_item();
}

void init()
{
	if(environment()==this_player())
		add_action("do_fly","fly");
}


string view(string room) {
	int i;
	object *inv,env;
	mapping exits;
	string roomdesc, str, *dirs;
	
	env = load_object(room);

	str = HIR BLK"\n��С������Ĵӷ�̺��Ե̽��ͷ������ȥ��\n\n"NOR;
	
	// room descriptions.
	str += sprintf( "%s \n%s",
			env->query("long"),

	// exits.
			env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	// all things in the room.
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("no_shown") ) {
			continue;
		}
		str += "  " + inv[i]->short() + "\n";
	}
	return str;
}



int do_fly()
{
	object me,room,env;
	me = this_player();
	room = environment(me);
	if (room->query("is_carpet"))
	{
		tell_object(me,"���Ѿ����ڷ�̺�����Σ�����\n");
		return 1;
	}
	if (me->is_fighting() || me->is_busy())
	{
		tell_object(me,"������û�п����Ϸ�̺��\n");
		return 1;
	}
	if (me->query("mana") < 100)
	{
		tell_object(me,"��ķ��������Լ����̺��\n");
		return 1;
	}
	me->add("mana",-100);	// prevent flood.
	if (!room->query("outdoors"))
	{
		message_vision(CYN"$N�����˷�̺���ȵ�����\n��̺����$N�����������磬��ž�һ���䵽���ϡ�\n"NOR,me);
		return 1;
	}
	if (room->query("no_fight") || room->query("no_magic") || room->query("no_spells"))
	{
		message_vision(CYN"$N�����˷�̺���ȵ�����\n���Ƿ�̺��$N����һ��������\n"NOR,me);
		return 1;
	}
	env = new(__DIR__"sp_carpet2");
	message_vision(CYN"$N��һ�ŷ�̺�̵����棬����������ȥ���ȵ�����\n\n��̺����$N����������ʧ������֮�У�����\n\n"NOR,me);
	me->move(env);
	call_out("do_release",1,me,room,env,0);
	return 1;
}

void do_release(object me,object room,object env,int count)
{
        string *msg = ({
CYN"\n��̺Խ��Խ�ߣ���������Щ�˷ܣ�����Щ���š�\n\n"NOR,
WHT"\n�����������������ԣ���ʪ������������������Щ���䡣\n\n"NOR,
CYN"\n��̺һ�����������Ʋ��д��˳�ȥ��\n\n"NOR,
"view/d/fy/fysquare",
WHT"\n��̺΢΢һ�Σ���������С�\n\n"NOR,
CYN"\n������������˵������������������֣����������ң���Щ����Ҳ�Ƶķ���æ����ʧ���ˡ���\n\n"NOR,
WHT"\n��̺����һ���뿪�����ܵ��Ʋ㡣\n\n"NOR,
"view/d/zhaoze/center",
CYN"\n��̺ת��һ������Ѹ�ٵ�������ȥ��\n\n"NOR,
"view/d/baiyun/jietiandian",
WHT"\n�����Ϸ����輱�����÷�̺Ʈ������һ����\n\n"NOR,
"view/d/changchun/moonding",
CYN"\n�뿪���ϵõĳ�����������̺��ת�򱱷���\n\n"NOR,
"view/d/shenshui/ocean1",
CYN"\n������������̺��������½�ص�ȥ��\n\n"NOR,
"view/d/laowu/street3",
WHT"\nһ�������ӹ������ԣ���תͷ������ֻ��һ���׷�ƮƮ������̤��һ�ѱ��������д���Զȥ��\n\n"NOR,
"view/d/zangbei/nianqing",
"view/d/biancheng/cemetery0",
CYN"\n��էȻ������������̺���Ŷ�������������ҡ�Ρ�\n\n"NOR,
"view/d/quicksand/greenland",
"view/d/huashan/shanlu1",
CYN"\n��Զ����ֻ�ɺ׻����ɹ����ױ����ƺ����м�����Ӱ��\n\n"NOR,
"view/d/shanliu/sheshenya",
HIY"\nһ�����������������߲������ƺ���������â��\n�������м�С�������ӵ��洫�����������̵ģ��ִ�ƫ�ˡ���\n\n"NOR,	// * snicker
"view/d/huangshan/pond",
"view/d/taoyuan/riverbanke",
WHT"\n��̺�������ת�˴���Ȧ����ʼ����·��ȥ��\n\n"NOR,
});

	if (!me || !env)
		return;
	if (!room)	// ���䶪ʧ?...Ӧ�ò���,���Ƿ�ֹ�������,��һ�¼��. ; annie.
	{
		room = load_object("/d/fy/fysquare");
		tell_object(me,CYN"\n��̺ͻȻʧȥ��ƽ�⣬�ڷ��з�������׹��\n\n����������������������������\n\n"NOR);
		me->move(room);
		message_vision(CYN"\nһ��ӳ�ڵ��ϵĺ�ӰԽ��Խ������ž�һ�����ڸɺԵ�ˮ���\n$N��ͷ�����Ĵ�ˮ�������˳�����\n\n"NOR,me);
		destruct(env);	// destruct used carpet
		return;
	}
	if (count < sizeof(msg))
	{
		if (msg[count][0..3]=="view") // view room.. 
			message_vision(view(msg[count][4..sizeof(msg[count])-1]),me);
		else
			message_vision(msg[count],me);
		count ++;
		call_out("do_release",1,me,room,env,count);
	}
	else
	{
		tell_object(me,CYN"\n��̺�������ڿ�������һȦ����ʼ�����½���\n\n"NOR);
		me->move(room);
		message_vision(CYN"\nһ���̺����$N�������䵽�˵����ϡ�\n\n"NOR,me);
		destruct(env);	
		return;
	}
}








