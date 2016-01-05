/*	DOOR_ROOM by silencer@fengyun4
***** 	To create a door in a room, 
*****	you need inherit DOOR_ROOM and #include <room.h>
	which has 	#define DOOR_CLOSED		1
			#define DOOR_LOCKED		2
			#define DOOR_SMASHED		4
				
A typical door format:

create_door("west", "door", "̴ľ��", "east", DOOR_CLOSED);

query_doors gives:
  		"west" : ([ 
	      			"id" : 		({ "west","̴ľ��","door",}) --- wierd old setup.
	        		"door_id":	it should just be id....
	        		"name" : 	"̴ľ��",
      				"status" : 	1,
      				"old_status":   1,
      				"other_side_dir" : "east",
    			]),

	DOORS will be reset to old status during each reset.
	More functions about LOCKED and SMASHED will be added later.
	
*/


#pragma save_binary
#include <ansi.h>
#include <dbase.h>
#include <room.h>

inherit ROOM;

static mapping doors;
mapping default_dirs = ([
		"north":		"��",
		"south":		"��",
		"east":			"��",
		"west":			"��",
		"northup":		"���߸ߴ�",
		"southup":		"�ϱ߸ߴ�",
		"eastup":		"���߸ߴ�",
		"westup":		"���߸ߴ�",
		"northdown":		"���ߵʹ�",
		"southdown":		"�ϱߵʹ�",
		"eastdown":		"���ߵʹ�",
		"westdown":		"���ߵʹ�",
		"northeast":		"����",
		"northwest":		"����",
		"southeast":		"����",
		"southwest":		"����",
		"up":			"��",
		"down":			"��",
		"out":			"��",
		"enter":		"��",
	]);

int reset_door();


void reset() {
	reset_door();
	:: reset();
}

// Redirect item_desc of the door to this function in default.
string look_door(string dir)
{
    	
    	string arg;
    	    	
    	if( !mapp(doors) || undefinedp(doors[dir]) )
        	return "��Ҫ��ʲ�᣿\n";
    	
	arg = dir;
	if( !undefinedp(default_dirs[arg]) )
			arg = default_dirs[arg];
	
    	if( doors[dir]["status"] & DOOR_CLOSED )
        	return "��"+arg+"�ķ�����"YEL + doors[dir]["name"] + NOR"�����ڹ�����\n";
    	else
        	return "��"+arg+"�ķ�����"YEL + doors[dir]["name"] + NOR"�����ڿ�����\n";
}


varargs int open_door(string dir, int from_other_side)
{
    	mapping exits;
    	object ob;

    	if( !mapp(doors) || undefinedp(doors[dir]) )
        	return notify_fail("�������û���š�\n");

    	if( !(doors[dir]["status"] & DOOR_CLOSED) )
        	return notify_fail( doors[dir]["name"] + "�Ѿ��ǿ������ˡ�\n");

    	exits = query("exits");
    	if( !mapp(exits) || undefinedp(exits[dir]) )
        	error("Room: open_door: attempt to open a door with out an exit.\n");

    	if( from_other_side )
        	message("vision", "���˴���һ�߽�" + doors[dir]["name"] + "���ˡ�\n",
                	this_object());
    	else if( objectp(ob = find_object(exits[dir])) ) {
        	if( !ob->open_door(doors[dir]["other_side_dir"], 1) ) return 0;
    	}

    	doors[dir]["status"] &= (!DOOR_CLOSED);
    	return 1;
}

varargs int close_door(string dir, int from_other_side)
{
    	mapping exits;
    	object ob;

    	if( !mapp(doors) || undefinedp(doors[dir]) )
        	return notify_fail("�������û���š�\n");

    	if( (doors[dir]["status"] & DOOR_CLOSED) )
        	return notify_fail( doors[dir]["name"] + "�Ѿ��ǹ������ˡ�\n");

    	exits = query("exits");
    	if( !mapp(exits) || undefinedp(exits[dir]) )
        	error("Room: close_door: attempt to open a door with out an exit.\n");

    	if(from_other_side )
        	message("vision", "���˴���һ�߽�" + doors[dir]["name"] + "�����ˡ�\n",
                this_object());
    	else if( objectp(ob = find_object(exits[dir])) ) {
        	if( !ob->close_door(doors[dir]["other_side_dir"], 1) ) return 0;
    	}

    	doors[dir]["status"] |= DOOR_CLOSED;
    	return 1;
}


int check_door(string dir, mapping door)
{
    // If we have no responding door, assume it is correct.
    	if( !mapp(doors) || undefinedp(doors[dir]) ) return 1;

    	door["status"] = doors[dir]["status"];
    	return 1;
}


varargs void create_door(string dir, string door_id,mixed data,string other_side_dir, int status)
{
    	mapping d, exits, item_desc;
    	object ob;

	// We are only allow to create a door if an exit exits.
    	exits = query("exits");
    	if( !mapp(exits) || undefinedp(exits[dir]) )
        	error("Room: create_door: attempt to create a door without exit.\n");

    	// The information of door in this room
    	if( stringp(data) )
    	{
        	d = allocate_mapping(6);
        	d["name"] = data;
        	d["door_id"] = door_id;
        	d["id"] = ({ dir, data, "door" });
		d["other_side_dir"] = other_side_dir;
        	d["status"] = status;
        	d["old_status"] = status;
    	}
    	else if( mapp(data) )
        	d = data;
    	else
        	error("Create_door: Invalid door data, string or mapping expected.\n");

	// Add a description to room
    	set("item_desc/" + dir, (: look_door, dir :) );
    	if (stringp(data)) {
    		set("item_desc/" + data,(: look_door, dir :) );
    		set("item_desc/" + door_id,(: look_door, dir :) );
	}
	
    	// check if the other room is set properly.
    	if( objectp(ob = find_object(exits[dir])) )
    	{
        	if( !ob->check_door(other_side_dir, d) )
            	return;
    	}

	// Add door parameter
    	if( !mapp(doors) ) doors = ([ dir: d ]);
    	else doors[dir] = d;
}


mapping query_doors() { return doors; }

mixed query_door(string dir, string prop)
{
    	if( !mapp(doors) || undefinedp(doors[dir]) ) return 0;
    	else return doors[dir][prop];
}

int reset_single_door(string dir, int the_other_side){
	object ob;
	mapping exits;
	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
        	error("Room: reset_door: attempt to reset a door without exit.\n");
	doors[dir]["status"] = doors[dir]["old_status"];
	if(objectp(ob = find_object(exits[dir])) && !the_other_side)	// two doors need to be sync.
		ob->reset_single_door(doors[dir]["other_side_dir"],1);
	return 1;
}

int reset_door(){
	string *door_exit;
	object ob;
	int i;
	
	if (!mapp(doors)) return 0;
	door_exit = keys(doors);
	if (!door_exit)	return 0;
	
	for (i = 0; i< sizeof(door_exit); i++) {
		if (doors[door_exit[i]]["status"] != doors[door_exit[i]]["old_status"]) 
			reset_single_door(door_exit[i],0);
	}
	return 1;
}

		

int valid_leave(object me, string dir)
{
    	if( mapp(doors) && !undefinedp(doors[dir]) ) {
        if( doors[dir]["status"] & DOOR_CLOSED )
            	return notify_fail("������Ȱ�" + doors[dir]["name"] + "�򿪣�\n");
        // if ( door[dir]["status"] & DOOR_HAS_TRAP ) ....
    	}
    	return 1;
}
