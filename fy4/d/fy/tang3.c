inherit ROOM;
void create()
{
    set("short", "��ʬ��");
    set("long", @LONG
��Ǯ��Ϊ�����켺��˫��Ѫ�ȣ��������ڶ��ҡ���Ȼ�ؽ���ͨ�ٸ����԰���
��������Ϊ���Ӷ���������������Թ������ֹ��Ϊ���˶�Ŀ����Ǯ��Ļ�ʬ����
�Ƿ�����״��ʬ��Ĵ��������˸ߵ���ͭ¯������ʢ��һ�ɽ�ʬ�Ķ������������
�������������
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"jhuang",
      ]));

    set("item_desc", ([
	"��ͭ¯":"���˸ߵ���ͭ¯�����ܻ���ȼ�յ�������һ���ͻ��̵�Ƥ���������ƺ������ƶ���\n",
	"ding": "���˸ߵ���ͭ¯�����ܻ���ȼ�յ�������һ���ͻ��̵�Ƥ���������ƺ������ƶ���\n",
	"lu": "���˸ߵ���ͭ¯�����ܻ���ȼ�յ�������һ���ͻ��̵�Ƥ���������ƺ������ƶ���\n",
	"oven": "���˸ߵ���ͭ¯�����ܻ���ȼ�յ�������һ���ͻ��̵�Ƥ���������ƺ������ƶ���\n",
      ]));

    set("coor/x",-180);
    set("coor/y",120);
    set("coor/z",0);
    set("map","fywest");
    setup();
}


void init()
{
    add_action("do_burn","burn");
    add_action("do_move",({"move","push"}));

}



int do_burn(string arg)
{
    object me;
    object tar;
    int score, pot, num;
    me = this_player();

    num = 900;

    if( !arg || arg == "") 
	return notify_fail("����ɶ������\n");
    tar = present(arg, me);
    if( !tar) 
	return notify_fail("������û���ⶫ����\n");
    if( userp(tar))
	return notify_fail("�㲻���ջ�Ķ�����\n");
    if( tar->query("owner"))
	return notify_fail("�㲻���ն��Ķ�����\n");
    if (tar->query("no_burn"))
	return notify_fail("�������������ա�\n");

    //	TO prevernt roboting burning corpse
    //	(1) unlimited spawn corpse cannot be burnt
    //	(2) You can gain 10 "corpse" every 15 minutes.
/*
    if( tar->is_corpse() && !tar->query("possessed"))		
    {
	if  (me->query("timer/burn")+ num < time()) 
	    me->set("timer/burn_corpse",0);

	if (!me->query("timer/burn_corpse") ) 
	    me->set("timer/burn",time());

	if (me->query("timer/burn")+ num < time() || me->query("timer/burn_corpse") < 10){
	    me->add("potential",  1);
	    me->add("timer/burn_corpse",1);
	}
  	}*/
    message_vision("$N��$nͶ������ͭ¯��$nת�ۻ�Ϊ�ҽ���\n", me, tar);
    tar->move(environment(me));
    destruct(tar);
    return 1;
}



int do_move(string arg)
{
    string msg;
    object room;
    if (!arg || (arg!= "��ͭ¯" && arg!= "ding" && arg!= "lu" && arg!="oven"))
	return notify_fail("�����ƶ�ʲô��\n");

    if (this_player()->query("force_factor")<60)
	return notify_fail("���þ�ȫ����ȥ����ͭ¯�����˸��Ƶģ���˿������\n");

    msg= this_player()->query("gender")=="����" ?
    "\n$N���һ�����������ƣ������ƿ���ͭ¯�� \n"
    : "\n$N��߳һ�����ٿ�һ�Ȼ���¯����ͭ¯��Ȼ�����ƿ��˰�ߡ�\n";
    message_vision(msg, this_player());
    message("vision","һ�����˵�����Ю�ź���ӭ������������ɢȥ��"+this_player()->name()+"��Ȼ��������ʧ�ˡ�\n",this_object(),this_player());
    tell_object(this_player(),"һ�����˵�����Ю�ź���ӭ�����������ƺ����ý��µ���ʯש�ƶ���������\n\n\n");
    room = find_object(AREA_MAZE"jq3-entry");
    if (!room) room = load_object(AREA_MAZE"jq3-entry");
    this_player()->move(room);
    return 1;
}



