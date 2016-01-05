#include <ansi.h>
inherit ITEM;
string description();

void create()
{
        set_name("����", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",(: description() :));
                set("no_split",0);
                set("value", 1000);
                set("material", "paper");
        }
}

string description() {
	string msg,required ;
	mapping data;

	data = F_LEVEL->exp_to_level(query("required_exp"));
	required = chinese_number(data["level"])+"������";
	required += query("required_class") ? F_MASTER->query_chinese_class(query("required_class"))+"���ӣ�"
			: "";

	required += "��������"+chinese_number(query("required_skill_level"))+"��"+SKILL_D(query("required_skill"))->name()+"\n";
	
	msg = sprintf("һ������˿�����д�ţ�
�书�ľ���%s
ѧϰ������%s\n"NOR,
			  query("name"),
			  required,
			);
	return msg;
}

void init()
{
   	add_action("do_read","read");
}
    
int do_read(string arg)
{
    	object me;
    	mapping data;
    	    
    	if(!arg || arg != "scroll"){
        	write("�����ʲô��\n");
        	return 1;
        }
        
    	me = this_player();
		if (me->query("class") != query("required_class"))
		{
			write("�Ȿ�����ϼ�¼���书�ķ����ʺ���������������Ҳû�á�\n");
        	return 1;
        }
        
		if (me->query_skill(query("required_skill"),1) < query("required_skill_level"))
		{
		write("����Ϊδ��������Ҳû�á�\n");
        	return 1;
        }
        
        if (me->query("combat_exp") < query("required_exp")) {
        	data = F_LEVEL->exp_to_level(query("required_exp"));
        	write("�㻹��������������书�ľ��裬������Ҫ"+ chinese_number(data["level"])+"�ȼ���\n");
    		return 1;
    	}
    	
    	if (me->query("annie/"+query("required_skill")+"_"+query("teaching")) >= query("grade"))
		{
    		write("���Ѿ�ѧ����������ϵ��书�ˡ�\n");
    		return 1;
    	}
    	
    	if (me->query("annie/"+query("required_skill")+"_"+query("teaching")) + 1 < query("grade"))
		{
    		write("����δ������һ���书��Ϊ��ǳ�����ż��գ����������ϰ�˹���\n");
    		return 1;
    	}
    	
    	message_vision(HIW"$NС������ش򿪾��ᡣ\n"NOR,me);
    	tell_object(me,HIC"�����ž����ϵķ������������������ǰ������������\n"NOR);
    	tell_object(me,HIC"һ����Ĺ��������ѧ��Ϊ������һ��¥��\n"NOR);
    	message_vision(HIG"Ƭ�̣�$N���еľ����������䣬�����һ��Ʈɢ�ڷ��С�\n"NOR,me);
    	me->perform_busy(1);
		me->set("annie/"+query("required_skill")+"_"+query("teaching")	,query("grade"));
		destruct(this_object());
    	return 1;
}
    