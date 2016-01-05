#include <dbase.h>
#include <name.h>
#include <ansi.h>
inherit COMBINED_ITEM;

void create() {
	if(clonep(this_object())) {
		destruct(this_object());
		return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
	}
}


void init()
{
  	if(this_player()==environment())
		add_action("apply_medicine",({"use","yong"}));
}


string 	herb_desc()
{
	string desc, type, pos;
	
	switch (query("field"))
	{
		case "kee":	pos = "��Ѫ"; break;
		case "gin":	pos = "����"; break;
		case "sen":	pos = "����"; break;
		default:	pos = "";
	}
		
	switch (query("type"))
	{
		case "poison":	desc = "������ҩ�ݣ�";
				desc += "�ж���"+ pos + "����"+ query("effect")+"�㣬��"
					+query("level")+"��ҩ�����ж�����Ϊ"+ query("proc")+"%��\n";
				break;
		case "cure":	desc = "��ҩ�ݿ�����"+query("effect")+ "��"+ pos+"���ˣ���"
					+query("level")+"��ҩ����\n";
				if (sscanf(query("heal_type"),"%s/%d",type, amount)== 2 )
				{
					desc += "ֱ�ӷ��ã�use��������"+(amount)+"��"+ pos+ "���ˡ�\n";	
				}
				break;
		case "full":	desc = "��ҩ�ݿ�����"+query("effect")+ pos+"���ˣ���"
					+query("level")+"��ҩ����\n";
				if (sscanf(query("heal_type"),"%s/%d",type, amount)== 2 )
				{
					desc += "ֱ�ӷ��ã�use��������"+amount+"��"+ pos+ "���ˡ�\n";	
				}
				break;
		case "depoison":desc = "��ҩ�ݿɽ�ȥ"+query("field")+"֮���ԣ���"
					+query("level")+"��ҩ����\n";
				break;
		default:  desc = "һ��ҩ�ݣ��������ʲô��Ч��\n";
	}
	if (query("extra_desc"))	desc = desc + query("extra_desc") + "\n";
	return desc;	
}


int apply_medicine(string arg)
{
	int amount;
	string type, verb, pos;
	int diff;
	
	if (arg == query("id") || arg == query("name")) {
//	if (arg!= query("id") && arg!= query("name"))
//		return notify_fail("��Ҫʹ����һ���������\n");
		if (this_player()->is_fighting())
		    	return notify_fail("������ս���У��Ƚ��������˵�ɡ�\n");
		if (this_player()->is_busy() && !query("pro_busy"))
		   	return notify_fail("��������æ����һ����ɡ�\n"); 	
		if (query("type") != "cure" && query("type")!= "full")
			return notify_fail("�����Ʒ���ʹ��û���������á�\n");
	
		if (sscanf(query("heal_type"),"%s/%d",type, amount)!= 2 )
			return notify_fail("�����Ʒû���������á�\n");
		
		diff = this_player()->query("max_"+type)-this_player()->query("eff_"+type);
		if(!(diff))    return notify_fail("��û�����ˣ�\n");
		
		amount = amount* (100 + this_player()->query_skill("prescription",1)/2)/100;
		if(amount > diff) amount = diff;
		this_player()->add("eff_"+type,amount);
		this_player()->status_msg(type);
		
		// This allows customization of eating effect.
		if( query("use_func")) {
			add_amount(-1);
			return 1;
		}
		
		switch (query("usage_type")) {
			case "pill":	verb = YEL"$N����һ��"+name(); break;
			case "piece":	verb = YEL"$N����һ��"+name(); break;
			case "herb":    verb = YEL"$N��"+name()+YEL"���÷����˿���"; break;
			default :	verb = YEL"$Nʹ��"+name();
		} 
			  
		message_vision(verb+"��\n"NOR,this_player());
		switch (type)
		{
			case "kee":	pos = "��Ѫ"; break;
			case "gin":	pos = "����"; break;
			case "sen":	pos = "����"; break;
			default:	pos = "";
		}
		tell_object(this_player(),"���"+pos+"������"+amount+"�㡣\n");
		this_player()->perform_busy(1);
		add_amount(-1);
		return 1;
	}
}



