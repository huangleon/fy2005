inherit ITEM;
void create()
{
        set_name("�������", ({ "necromancy_book" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"һ��������̵�����ؼ���");
                set("value", 0);
                set("no_stack", 1);
                set("material", "paper");

				set("is_fake_necbook",1);
        }
    ::init_item();
}


void init()
{
  if(this_player()==environment())
  add_action("do_study","study");
}
int do_study(string arg)
{
        object me,ob;
        int sena;
        int cps;
        string book;
        me = this_player();
        cps = random((int)me->query("cps"));
       if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
                return notify_fail("ָ���ʽ��study <��> <������>\n");
        if( (string)book != "necromancy_book")
                return notify_fail("��Ҫ��ʲ�᣿\n");
        if(!objectp(ob = present(book, me)) )
                return notify_fail("��Ҫ��ʲ�᣿\n");
        tell_object(this_player(),"���Ȼ�Ǳ��������飡��\n");

        return 1;
}


int init_spawn()
{
	object room;
	room = find_object("/d/taoguan/book_room2");
	if (!room)
		room = load_object("/d/taoguan/book_room2");
	if (!room)
		return 0;

	room = present("��¯",room);
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

