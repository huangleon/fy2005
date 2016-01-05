// food.c

#include <dbase.h>
#include <name.h>

void init()
{
	if(environment()==this_player())
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	int avai,remain, cost;
	mixed no_meal;
	
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
	if ( no_meal = environment(this_player())->query("no_meal"))
	{
		if (stringp(no_meal))
			return notify_fail(no_meal);
		else 
			return notify_fail("�˵ؽ�ֹ�Ժȡ�\n");
	}
	if( !query("food_remaining") )
		return notify_fail( name() + "�Ѿ�ûʲ��óԵ��ˡ�\n");
	if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");
	remain = (int) query("food_remaining") * (int) query("food_supply");
	avai = (int)this_player()->max_food_capacity() - (int)this_player()->query("food");
        if( remain > avai )
        {
        	this_player()->add("food", avai);
        	cost = (avai/query("food_supply")>0)? avai/query("food_supply"):1;
        	add("food_remaining", -cost);
        }
        else
        {
        	this_player()->add("food",remain);
        	set("food_remaining", 0);
        }

	if( this_player()->is_fighting() )
		this_player()->start_busy(3);
	else
		this_player()->start_busy(1);

	// This allows customization of drinking effect.
	if(query("eat_func")) return 1;

	set("value", 0);
	if( !query("food_remaining") ) {
		if (!query("finish_msg"))
			message_vision("$N�����е�" + name() + "�Եøɸɾ�����\n", this_player());
		else
			message_vision(query("finish_msg"), this_player());				
		if( !this_object()->finish_eat() )
			destruct(this_object());
	} else 
		message_vision("$N����" + name() + "ҧ�˼��ڡ�\n", this_player());

	return 1;
}

