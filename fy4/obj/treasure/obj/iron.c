inherit ITEM;
void create()
{
        set_name("������", ({ "rusty iron" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("no_stack", 1);
				set("no_clean_up",1);
				set("no_reset",1);

							set("weapon_material",1);
			set("material_level",61);
			set("desc_ext","��������(61)��");

		}
    ::init_item();
}


int init_spawn()
{
	object room;
	room = find_object("/d/huangshan/xuanyuan");
	if (!room)
		room = load_object("/d/huangshan/xuanyuan");
	if (!room)
		return 0;

	move(room);
	return 1;
}

/*

void remove_all_killer()	// ��Ϊdestruct��ʽ�к��������func����itemû��ԭ���壬��˿������������protect��ֹ���� annie.
{
	if (environment())
		SPAWN_D->restart_spawn(query("spawn_num"),0);
	return;
}

*/



/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

