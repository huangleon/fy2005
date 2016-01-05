inherit ITEM;

void create()
{
	set_name("���ƽ���" , ({ "swordbook" }) );
        set_weight(600);
        set("unit", "��");
        set("long", "һ����ȱ��ȫ�Ľ��ף���ߵ�һ���Ѿ����ٻ٣����ÿ����ʽ��ֻʣ��һ�롣\n");
        set("value", 1000);
        set("no_get",1);
        set("no_drop",1);
        set("no_sell",1);
        set("skill", ([
                "name":         "xiaohun-sword",      
                "exp_required": 1500000,       
                "sen_cost":       20   ,
                "difficulty":  30,  
                "max_skill":   10,
        ]) );
}
 
void init()
{
	add_action("do_study","study");
}

int do_study(string arg)
{
	string book;
	int sena;
	
	object me=this_player();
	if(me->query("marks/���",1))
		return 0;
        if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
    		    return 0;
        if(this_object()==present(book,me))
        {
		tell_object(me,"�Ȿ�����Ѿ����Ʋ�ȫ���޷�������ѧ���κζ�����\n");
		return 1;
	}
	return 0;
}
