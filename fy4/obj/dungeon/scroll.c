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
                set("value", 1000);
		set("teaching", "riposte");
		set("fy41","nonsense");
		set("required_exp", 5000000);
		set("required_class","none");
                set("material", "paper");
        }
}

string description() {
	string msg,required ;
	
	required = query("required_class") ? F_MASTER->query_chinese_class(query("required_class"))+"���ӣ�"
			: "";
	msg = YEL"һ���ᣬɢ����һ�ɵ��������㣬����д�ţ�����䣩\n"NOR;
	msg += sprintf(WHT"�书�ľ���\t\t%s��%s��\n"
			  "ѧϰ������\t\t\%s\n"NOR,
			  query("name"),query("teaching"),
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
    	mapping data, data2;
    	    
    	if(!arg || arg != "scroll"){
        	write("�����ʲô��\n");
        	return 1;
        }
        
    	me = this_player();
	
	if (me->is_busy() || me->is_fighting()) {
		write("�����ڻ����ܾ���������\n");
		return 1;
	}
		
	if (me->query("class")!= query("required_class")) {
		write("�Ȿ�����ϼ�¼���书�ķ����ʺ���������������Ҳû�á�\n");
        	return 1;
        }
        
        data = F_LEVEL->exp_to_level(query("required_exp"));
        data2 = F_LEVEL->exp_to_level(me->query("combat_exp"));
        
        if (data2["level"] < data["level"]) {
        	
        	write("�㻹��������������书�ľ��裬������Ҫ"+ chinese_number(data["level"])+"�ȼ���\n");
    		return 1;
    	}
    	
    	if (me->query("fy41/"+query("fy41"))) {
    		write("���Ѿ�ѧ����������ϵ��书�ˡ�\n");
    		return 1;
    	}
    	
    	message_vision(YEL"$NС������ش򿪾��ᡣ\n"NOR,me);
    	tell_object(me,YEL"�����ž����ϵķ������������������ǰ������������\n"NOR);
    	tell_object(me,YEL"һ����Ĺ��������ѧ��Ϊ������һ��¥��\n"NOR);
    	message_vision(HIG"�����������䣬�������һ��Ʈɢ�ڷ����ˡ�\n"NOR,me);
    	me->perform_busy(1);
    	me->set("fy41/"+query("fy41"),1);
    	destruct(this_object());
    	return 1;
}
    