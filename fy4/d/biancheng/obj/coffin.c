inherit ITEM;
#include <ansi.h>


void create()
{
        set_name("�ײ�", ({ "coffin","�ײ�" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
	}
	set("closed",1);
	set("burnt",0);
	::init_item();
}

void init()
{
	add_action("do_open","open");
	add_action("do_look","look");
}


int do_look(string arg){
	object ob,me;
	me=this_player();
	ob=this_object();
	
	if (arg=="coffin" || arg=="�ײ�"){
		if (query("burnt")) tell_object(me,"һ���յúں����Ĺײļ��ӣ�ʲôҲ����������\n");
		else if (query("burning")) tell_object(me,"�������ܣ��ۿ���Ҫ�ѹײ��ջ��ˡ�\n");
		else if (!query("closed")) tell_object(me,"һ������ͨͨ�Ĺײģ��������Ÿ����ˡ�\n");
		else if (!me->query("marks/wanma/׼��ɱ�̿�_ma"))
			tell_object(me,"�ײı�����ȫ�µģ���ú���������ȴ�ѱ������˺ܶ�ط���\n");
		else tell_object(me,"�ײı�����ȫ�µģ���ú���������ȴ�ѱ������˺ܶ�ط�����ϸ����һ�£�
�м����ײ�����������ˣ�Ҳ��Ӧ�ô�����һ�¡�\n");
		return 1;
	}
	return 0;
}
			

int do_open(string arg)
{
	object	me, ob,tuozi;
        seteuid(getuid());
        
        if( !arg || (arg != "coffin"&& arg != "�ײ�") ) 
        		return 0;
        
        me = this_player();
	ob = this_object();
	
	if (!me->query("marks/wanma/׼��ɱ�̿�_ma")) {
		tell_object(me,"�ײ���ʲô�����ģ�������\n");
		return 1;
	}
	
	if (!query("closed")) {
		tell_object(me,"�ײ��Ѿ��Ǵ򿪵��ˡ�\n");
		return 1;
	}
	
	if (tuozi=present("ding qiu",environment(ob))) {
		tell_object(me,tuozi->name()+"˵������ô����������ײ���Ҫ��Ҫ������һ�Σ���\n");
		return 1;
	}
	
	if (!environment(ob)->query("tuozi_out")) {
		message_vision(HIB"����һ���������������¸������µ����ӵ��ڹײ�ǰ��\n"NOR,me);
		tuozi=new(AREA_BIANCHENG"npc/tuozi");
		if (tuozi) tuozi->move(environment(ob));
		environment(ob)->set("tuozi_out",1);
		return 1;
	}
		
	if (query("burnt")) {
		tell_object(me,"���ˣ��ײ��Ѿ��յ�һ����ڣ�ʲôҲ���������ˡ�\n");
		return 1;
	}	
	
	message_vision("$N����֨��һ�������ײĸǴ��ˡ�����\n", me, ob);
	tell_object(me,YEL"�򿪹׸ǣ������Ȼ���ǿյġ��״����и����ˣ����⼸�߹ײ�Ҳ��һ����
�ײ��������ˣ������Ǽ���ֵ��¡���������Щ���˾�Ȼ�����ϵ�����ʵ��
�´��ġ������ġ����ϰ�ͺ��ƹ���Щ�˸ղ������������ϵģ���ô��
��Ȼ����������������ϵ���Щ�ǡ�����������\n"NOR);
	me->set("marks/wanma/�ײ�֮��",1);
	ob->set("long","�ײĸ��Ѿ����򿪣��������Ÿ����ˡ�\n");
	ob->set("closed",0);
        return 1;
}

int is_container() { return 1; }

